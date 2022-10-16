#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int cnt0=0,cnt1=0;
    int cnt10=0,cnt11=0;
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<n;i++){
        if(s1[i]=='0')cnt0++;
        else cnt1++;
        if(s2[i]=='0'){
            if(s1[i]=='0')cnt10++;
            else cnt11++;
        }
    }
    cout<<cnt11*cnt0+cnt10*cnt1-cnt11*cnt10<<endl;
    return 0;
}