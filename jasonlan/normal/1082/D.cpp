#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=510;
int n;
int fa[maxn],cnt[maxn],dep[maxn];
int ans,cdeg;
vector <int> q1,q2;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();
	for(register int i=1;i<=n;++i){
		cnt[i]=read();
		if(cnt[i]==1)
			q1.push_back(i);
		else
			q2.push_back(i);
	}
	for(register int i=1;i<q2.size();++i){
		fa[q2[i]]=q2[i-1];
		--cnt[q2[i-1]];--cnt[q2[i]];
	}
	if(q1.size()==n){
		printf("NO");return 0;
	}
	if(q1.size()){
		fa[q1[0]]=q2[0];--cnt[q2[0]];++ans;
	}
	if(q1.size()>=2){
		if(!cnt[q2[q2.size()-1]]){
			printf("NO");return 0;
		}
		fa[q1[1]]=q2[q2.size()-1];--cnt[q2[q2.size()-1]];++ans;
	}
	for(register int i=2,j=0;i<q1.size();++i){
		while(j<q2.size()&&!cnt[q2[j]])++j;
		if(j==q2.size()){
			printf("NO");return 0;
		}
		fa[q1[i]]=q2[j];
		--cnt[q2[j]];
	}
	printf("YES %d\n%d\n",ans+q2.size()-1,n-1);
	for(register int i=1,j=0;i<=n;++i){
		if(fa[i]){
            if(!j){
                printf("%d %d",i,fa[i]);j=1;
            }
            else
                printf("\n%d %d",i,fa[i]);
        }
    }
	return 0;
}