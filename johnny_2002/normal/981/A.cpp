#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

int main(){
        string s;
        cin>>s;
        int n=s.length();
        int ans=0;
        for(int st=0;st<n;st++)
                for(int en=0;en<n;en++){
                        string cur=s.substr(st,en-st+1);
                        string rcur=cur;
                        reverse(rcur.begin(),rcur.end());
                        if (cur!=rcur) ans=max(ans,en-st+1);
                }
        cout<<ans;
}