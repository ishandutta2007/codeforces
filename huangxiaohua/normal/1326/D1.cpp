#include<bits/stdc++.h>
using namespace std;

int t,n,resa,resb,resc,resd,rese,i,j,an,bn,cn,dn,en;
char s[6666],a[6666],b[6666],c[6666],d[6666],e[6666];

int main(){
	scanf("%d\n",&t);
	while(t--){
		gets(s);
		n=strlen(s);
		resa=resb=resc=resd=rese=an=bn=cn=dn=en=0;
		
		for(i=1;i<=n;i++){
			an++;
			a[an]=s[i-1];
			for(j=1;j<=(an+1)/2;j++){
				if(a[j]!=a[an+1-j]){goto aaa;}
			}resa=an;
			aaa:continue;
		}
		if(resa==n){puts(s);continue;}
		for(i=n;i>=1;i--){
			bn++;
			b[bn]=s[i-1];
			for(j=1;j<=(bn+1)/2;j++){
				if(b[j]!=b[bn+1-j]){goto bbb;}
			}resb=bn;
			bbb:continue;
		}
		
		for(i=1;i<=(n+1)/2;i++){
			if(s[i-1]==s[n-i]){cn++;c[cn]=s[i-1];resc=cn;continue;}
			else{break;}
		}
		if(resc*2>=n){puts(s);continue;}
		
		for(i=1+cn;i<=n-cn;i++){
			dn++;
			d[dn]=s[i-1];
			for(j=1;j<=(dn+1)/2;j++){
				if(d[j]!=d[dn+1-j]){goto ddd;}
			}resd=dn;
			ddd:continue;
		}

		for(i=n-cn;i>=1+cn;i--){
			en++;
			e[en]=s[i-1];
			for(j=1;j<=(en+1)/2;j++){
				if(e[j]!=e[en+1-j]){goto eee;}
			}rese=en;
			eee:continue;
		}
		
		if(resa>=resb&&resa>=(resc*2+rese)&&resa>=(resc*2+resd)){
			for(i=1;i<=resa;i++){printf("%c",a[i]);}puts("");continue;
		}
		
		if(resb>=resa&&resb>=(resc*2+rese)&&resb>=(resc*2+resd)){
			for(i=1;i<=resb;i++){printf("%c",b[i]);}puts("");continue;
		}
		
		if(resd>=rese){
			for(i=1;i<=resc;i++){printf("%c",c[i]);}
			for(i=1;i<=resd;i++){printf("%c",d[i]);}
			for(i=resc;i>=1;i--){printf("%c",c[i]);}
			puts("");continue;
		}
		
		if(rese>=resd){
			for(i=1;i<=resc;i++){printf("%c",c[i]);}
			for(i=1;i<=rese;i++){printf("%c",e[i]);}
			for(i=resc;i>=1;i--){printf("%c",c[i]);}
			puts("");continue;
		}
	}
}