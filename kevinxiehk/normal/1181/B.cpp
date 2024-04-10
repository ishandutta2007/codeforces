#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std; 
int l;
string s;
int place=0;
main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    cin>>l>>s;
    int t=l/2;
    while(s[t]=='0'&&s[l-t]=='0')t--;
    string s1=s.substr(0,(l-t));
    string s2=s.substr(t,l-t);
    string ans;
    if((s1<s2||s[t]=='0')&&s[l-t]!='0'){
        ans=s1;
        for(int i=l-1;i>=(l-t);i--){
            ans[l-t-1-(l-1-i)]+=(s[i]-'0');
            if(ans[l-t-1-(l-1-i)]>'9'){
                ans[l-t-1-(l-1-i)]-=10;
                ans[l-t-1-(l-1-i)-1]++;
            }
        }
    }
    else {
        ans=s2;
        for(int i=t-1;i>=0;i--){
            ans[l-t-1-(t-1-i)]+=(s[i]-'0');
            if(ans[l-t-1-(t-1-i)]>'9'){
                ans[l-t-1-(t-1-i)]-=10;
                ans[l-t-1-(t-1-i)-1]++;
            }
        }
    }
    for(int i=ans.length()-1;i>0;i--){
        if(ans[i]>'9'){
            ans[i]-=10;
            ans[i-1]++;
        }
    }
    if(ans[0]>'9'){
        ans[0]-=10;
        cout<<'1';
    }
    cout<<ans<<endl;
	return 0;
}