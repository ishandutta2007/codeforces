#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,i,j,k,res[200500],st1[200500][20],st2[200500][20];

int l2(int n){int r=0;while(n-1){r++;n>>=1;}return r;}
int chk1(int l,int r){int k=l2(r-l+1);return max(st1[l][k],st1[r-(1<<k)+1][k]);}
int chk2(int l,int r){int k=l2(r-l+1);return min(st2[l][k],st2[r-(1<<k)+1][k]);}

struct sb{
	int id,l,r;
	bool operator<(const sb x)const{return r>x.r;}
}tmp,s[200500];
vector<sb> v[200500];
priority_queue<sb> q;

void ans(){
	for(int i=1;i<=n;i++){printf("%d ",res[i]);}puts("");
}

int main(){
	memset(st2,0x3f,sizeof(st2));
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&j,&k);
		s[i].id=i;
		s[i].l=j;s[i].r=k;
		v[j].push_back(s[i]);
	}
	for(i=1;i<=n;i++){
		for(auto j:v[i]){q.push(j);}
		s[i]=q.top();q.pop();
		res[s[i].id]=i;
		st1[i][0]=s[i].r;
		st2[i][0]=s[i].l;
	}
	for(j=1;j<=18;j++){
		for(i=1;i+(1<<j)-1<=n;i++){
			st1[i][j]=max(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
			st2[i][j]=min(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
		}
	}
	for(i=1;i<=n;i++){
		if(s[i].l<i&&chk1(s[i].l,i-1)>=i){
			puts("NO");
			ans();
			for(j=i-1;;j--){
				if(s[j].r>=i){
					swap(res[s[i].id],res[s[j].id]);break;
				}
			}
			ans();return 0;
		}
		if(s[i].r>i&&chk2(i+1,s[i].r)<=i){
			puts("NO");
			ans();
			for(j=i+1;;j++){
				if(s[j].l<=i){
					swap(res[s[i].id],res[s[j].id]);break;
				}
			}
			ans();return 0;
		}
	}
	puts("YES");ans();
}