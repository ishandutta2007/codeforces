#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<queue>
#include<cstdio>
#include<vector>
#define f first 
#define s second 
#define mp make_pair 
#define ll long long

using namespace std;


string s,S;
int n;

int main(){
//        freopen("input","r",stdin);
//        freopen("output","w",stdout);

        cin>>n;
        int cnt = 0;
        for(int i = 0;i < n;i++) {
        	cin>>s;
        	bool ok = 1;
        	int l = s.size();
        	if(s[0] == '0') {
        		cout<<"0";
        		return 0;
        	}
        	if(s[0] != '1') ok = 0;
        	for(int i = 1;i < l;i++) if(s[i] != '0')
        		ok = 0;
        	if(!ok) S = s;
        	else cnt += l - 1;
        }
        if(S.size() > 0) cout<<S;
        else cout<<'1';
        for(int i = 0;i < cnt;i++)
        	cout<<'0';

	return 0;
}