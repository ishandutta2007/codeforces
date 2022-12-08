#include <bits/stdc++.h>
using namespace std;

bitset<2001> dp[1<<16];
int n,k,c[20],b[20];

inline void Make(int &s,int &id){
	if(id*k<=2000){
		if(dp[s][id*k]){
			// cout << "OP1" << endl;
			for(int i=0;i<n;i++)if(1&(s>>i))
				b[i]++;
			id*=k;
			return ;
		}
	}
	//cout << s << " " << id << endl;
	for(int i=0;i<n;i++)if(1&(s>>i))if(id-c[i]>=0){
		if(dp[s-(1<<i)][id-c[i]]){
			s-=(1<<i);
			id-=c[i];
			return ;
		}
	}
}

bool del[20];

void merge(int x,int y){
	c[x]+=c[y];
	while(c[x]%k==0){
		b[x]--,c[x]/=k;
	}
	del[y]=1;
}
void Construct(){
	for(int T=1;T<n;T++){
		int Max = 0;
		vector<int> maxid(0,0);
		for(int i=0;i<n;i++)if(!del[i]){
			if(b[i] > Max)Max=b[i],maxid = vector<int> (1,i);
			else if(b[i] == Max)maxid.push_back(i);
		}
		int x=maxid[0],y=maxid[1];
		printf("%d %d\n",c[x],c[y]);
		merge(x,y);
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",&c[i]);
	dp[0][0]=1;
	for(int s=0;s<1<<n;s++){
		for(int sum=(2000/k)*k;sum;sum-=k){
			if(dp[s][sum]){
				dp[s][sum/k]=1;
			}
		}
		for(int j=0;j<n;j++)if(!(1&(s>>j))){
			dp[s|(1<<j)]|=dp[s]<<c[j];
		}
	}
	if(!dp[(1<<n) - 1][1]){
		puts("NO");
		return 0;
	}
	puts("YES");
	int curs = (1<<n) - 1, cury = 1;
	while(curs)
		Make(curs,cury);
	Construct();
}