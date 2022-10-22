#include<cstdio>
char c[1005];int n,p;
int main(){
	scanf("%d%d%s",&n,&p,c);
	for(int i=n-1;~i;--i){
		bool ok=0;
		for(++c[i];c[i]<'a'+p;++c[i]){
			if(i&&c[i]==c[i-1])continue;
			if(i>1&&c[i]==c[i-2])continue;
			ok=1;break;
		}
		if(ok){
			bool can=1;
			for(int j=i+1;j<n;++j){
				c[j]='a';
				for(;c[j]<'a'+p;++c[j]){
					if(j&&c[j]==c[j-1])continue;
					if(j>1&&c[j]==c[j-2])continue;
					break;
				}
				if(c[j]=='a'+p){can=0;break;}
			}
			if(can)return puts(c),0;
		}
	}
	puts("NO");
	return 0;
}