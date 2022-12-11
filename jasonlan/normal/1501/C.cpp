#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=201000,maxv=5100000;
int n;
struct note{
	int a,pos;
}v[maxn];
bool cmp(note x,note y){
	return x.a<y.a;
}
int buc[maxv][2];
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
void process(){
	n=read();
	for(int i=1;i<=n;++i){
		v[i].a=read();
		v[i].pos=i;
	}
	sort(v+1,v+1+n,cmp);
	for(int i=1;i<=n;++i){
		for(int j=i+1,t;j<=n;++j){
			t=v[i].a+v[j].a;
			if(!buc[t][0]){
				buc[t][0]=i;
				buc[t][1]=j;
			}
			else if(buc[t][0]==i||buc[t][0]==j||buc[t][1]==i||buc[t][1]==j)continue;
			else{
				puts("YES");
				printf("%d %d %d %d",v[buc[t][0]].pos,v[buc[t][1]].pos,v[i].pos,v[j].pos);
				return;
			}
		}
	}
	puts("NO");
}
int main(){
	int T=1;
	while(T--)process();
    return 0;
}