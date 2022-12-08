#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){

	long long int n;
	int q;
	cin>>n>>q;
	long long int d=-1ll,n2ll=n+1ll;
	while(n2ll%2==0){
		n2ll=n2ll/2;
		d++;
	}

	for(int p=0;p<q;p++){

		long long int s=0;
		cin>>s;
		long long int sp=s,mar=0,mar2ll=1ll<<(long long int)(d),mar3=0;
		long long int ds=0;
		while(mar3==0){
			if ((long long int)(s)%(long long int)(mar2ll)==0){
				ds=mar;
				mar3=1ll;
			}
			else {
				mar2ll=mar2ll/2ll;
				mar++;
			}
		}
		string cha;
		cin>>cha;
		for (int q=0; q<cha.size();q++){
			if (cha[q]=='R'){
				if((long long int)(s)%2ll==0){
					s+=1ll<<(long long int)(d-ds-1ll);
					ds++;
				}
			}
			if (cha[q]=='L'){
				if((long long int)(s)%2ll==0){
					s-=1ll<<(long long int)(d-ds-1ll);
					ds++;
				}
			}
			if (cha[q]=='U'){
				if((long long int)(s)!=1ll<<(long long int)(d)){
					long long int x=s;
					
                x=(long long int)(x-(1ll<<(long long int)(d-ds)))%(1ll<<(long long int)(d-ds+2ll));
					if (x!=0){
						s-=1ll<<(long long int)(d-ds);
					}
					if (x==0){
						s+=1ll<<(long long int)(d-ds);
					}
					ds--;
				}
			}
			//cout << s << endl;
		}
		cout<<s<<"\n";

	}


	return 0;
}