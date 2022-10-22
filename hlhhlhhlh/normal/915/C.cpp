#include<bits/stdc++.h>
using namespace std;
char a[30],b[30],d[30];
long long i,j,k,ha[20],c[20],len1,len2,ans=0,anss,haa[20],fla=1;
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c-'0'<0)||(c-'0'>9)){ if(c=='-') fh=-1; c=getchar(); }
	while ((c-'0'>=0)&&(c-'0'<=9)){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
void work(int x){
	int i,r,fla2=0;
	for (i=0;i<=10;i++) c[i]=ha[i];
	for (i=0;i<=x-1;i++){
		c[b[i]-'0']--;
		d[i]=b[i];
		if (c[b[i]-'0']<0) return;
	}
	for (i=9;i>=0;i--){
		if ((b[x]-'0'>i)&&(c[i]>0)){
			d[x]=i+'0';
			c[i]--;
			fla2=1;
			break;
		}
	}
	if (fla2==0) return;
	r=x;
	for (i=9;i>=0;i--){
		while (c[i]!=0){
			r++; d[r]=i+'0';
			c[i]--;
		}
	}
	ans=0;
	for (i=0;i<=r;i++){
		ans=ans*10+d[i]-'0';
	}
	if (ans>anss) anss=ans;
}
int main(){
	scanf("%s",a);
	scanf("%s",b);
	len1=strlen(a);
	len2=strlen(b);
	anss=0;
	for (i=0;i<=len1-1;i++){
		ha[a[i]-'0']++;
	}
	if (len1<len2){
		for (i=9;i>=0;i--){
			while (ha[i]!=0){
				ha[i]--;
				anss=anss*10+i;
			}
		}
		printf("%I64d\n",anss);
		return 0;
	}
	for (i=0;i<=len2-1;i++){
		haa[b[i]-'0']++;
	}
	for (i=0;i<=9;i++){
		if (haa[i]!=ha[i]) fla=0;
	}
	if (fla==1){
		for (i=0;i<=len2-1;i++){
			anss=anss*10+b[i]-'0';
		}
		printf("%I64d\n",anss);
		return 0;
	}
	for (i=len2-1;i>=0;i--){
		work(i);
	}
	printf("%I64d\n",anss);
	return 0;
}