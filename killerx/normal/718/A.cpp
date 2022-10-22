#include<bits/stdc++.h>
using namespace std;
string s;
int n,t;
void addone(int i,int&ps,int&fst,int lst){
	for(int j=fst;j<=lst;++j)s[j]='0';
	for(;~i&&(s[i]=='9'||s[i]=='.');--i)
		if(s[i]=='9')s[i]='0';
	if(i<0){
		s="1"+s;
		ps++;fst++;n++;
	}else s[i]++;
}
int main(){
	cin>>n>>t>>s;
	int ps=0;
	for(;ps<n&&s[ps]!='.';++ps);
	if(ps==n)cout<<s<<endl;
	else{
		int fst=n;
		for(int i=ps+1;i<n;++i){
			if(s[i]>='5'){
				fst=i;break;
			}
		}
		if(fst==n)cout<<s<<endl;
		else{
			addone(fst-1,ps,fst,n-1);
			while(--t&&fst>ps){
				int lst=fst;
				for(--fst;fst>ps&&s[fst]<'5';--fst);
				if(fst==ps)break;
				addone(fst-1,ps,fst,lst-1);
			}
			while(s.back()=='0')s.pop_back();
			if(s.back()=='.')s.pop_back();
			cout<<s<<endl;
		}
	}
	return 0;
}