#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb,lst;

int main(void){
    ios::sync_with_stdio(0);
    //cin>>t;
    t=1;
    while(t--){
    	cin>>n>>m;
    	string s(m,'0');
    	vector<pair<int,int> >v;
    	for(i=0;i<m;i++){
    		s[i]='1';
    		cout<<"? "<<s<<endl;
    		cin>>k;
    		v.push_back({k,i});
    		s[i]='0';
		}
		sort(v.begin(),v.end());
		lst=0;
		for(auto [x,y]:v){
			s[y]='1';
			cout<<"? "<<s<<endl;
			cin>>k;
			if(k==(lst+x)){
				lst=k;continue;
			}
			else{
				s[y]='0';
			}
		}
		cout<<"! "<<lst<<endl;
	}
}