#include <stdio.h>
#include <vector>
#define MAX (long long int)1e15

long long int abs(long long int k)
{
	return k>0?k:-k;
}

struct str{
	long long int dist11;
	long long int dist12;
	long long int dist21;
	long long int dist22;
};
str merge(str A, str B)
{
	long long int dist11 = A.dist11+B.dist11<A.dist12+B.dist21?A.dist11+B.dist11:A.dist12+B.dist21;
	long long int dist12 = A.dist11+B.dist12<A.dist12+B.dist22?A.dist11+B.dist12:A.dist12+B.dist22;
	long long int dist21 = A.dist21+B.dist11<A.dist22+B.dist21?A.dist21+B.dist11:A.dist22+B.dist21;
	long long int dist22 = A.dist21+B.dist12<A.dist22+B.dist22?A.dist21+B.dist12:A.dist22+B.dist22;
	return {dist11,dist12,dist21,dist22};
}

struct segTree{
	str value[400010];
	
	void setValue(int ind, str val, int l=1, int r=100000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = merge(value[2*v],value[2*v+1]);
		}
	}
	str getValue(int L, int R, int l=1, int r=100000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return {0,MAX,MAX,0};
		else if(R<l) return {0,MAX,MAX,0};
		else
		{
			int h = (l+r)/2;
			str A = getValue(L,R,l,h,2*v);
			str B = getValue(L,R,h+1,r,2*v+1);
			return merge(A,B);
		}
	}
}T;

int dist(int x1, int y1, int x2, int y2)
{
	if(x1==x2) return abs(y1-y2);
	if(y1==y2) return abs(x1-x2);
	
	int M = x1>y1?x1:y1;
	return abs(x1-M) + abs(y1-M) + abs(x2-M) + abs(y2-M);
}

std::pair<int,int> P1[100010],P2[100010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c,d,e;
		scanf("%d%d%d%d",&b,&c,&d,&e);
		P1[i] = std::make_pair(b,c);
		P2[i] = std::make_pair(d,e);
	}
	
	for(int i=2;i<a;i++)
	{
		int dist11 = dist(P1[i-1].first+1,P1[i-1].second,P1[i].first,P1[i].second)+1;
		int dist12 = dist(P1[i-1].first+1,P1[i-1].second,P2[i].first,P2[i].second)+1;
		int dist21 = dist(P2[i-1].first,P2[i-1].second+1,P1[i].first,P1[i].second)+1;
		int dist22 = dist(P2[i-1].first,P2[i-1].second+1,P2[i].first,P2[i].second)+1;
		T.setValue(i,{dist11,dist12,dist21,dist22});
	}
	
	int b;
	scanf("%d",&b);
	while(b--)
	{
		int c,d,e,f;
		scanf("%d%d%d%d",&c,&d,&e,&f);
		int type1 = c>d?c:d;
		int type2 = e>f?e:f;
		if(type1>type2)
		{
			int temp;
			temp = c;
			c = e;
			e = temp;
			temp = d;
			d = f;
			f = temp;
			temp = type1;
			type1 = type2;
			type2 = temp;
		}
		
		if(type1==type2) printf("%d\n",dist(c,d,e,f));
		else
		{
			str A = T.getValue(type1+1,type2-1);
			long long int ans1 = dist(P1[type1].first,P1[type1].second,c,d) + 1 + A.dist11 + dist(P1[type2-1].first+1,P1[type2-1].second,e,f);
			long long int ans2 = dist(P2[type1].first,P2[type1].second,c,d) + 1 + A.dist21 + dist(P1[type2-1].first+1,P1[type2-1].second,e,f);
			long long int ans3 = dist(P1[type1].first,P1[type1].second,c,d) + 1 + A.dist12 + dist(P2[type2-1].first,P2[type2-1].second+1,e,f);
			long long int ans4 = dist(P2[type1].first,P2[type1].second,c,d) + 1 + A.dist22 + dist(P2[type2-1].first,P2[type2-1].second+1,e,f);
			long long int ans = ans1;
			ans = ans<ans2?ans:ans2;
			ans = ans<ans3?ans:ans3;
			ans = ans<ans4?ans:ans4;
			printf("%lld\n",ans);
		}
	}
}