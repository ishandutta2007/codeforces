#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<x;i++){
        if(i==y){
            if(s[n-1-i]!='1')cnt++;
        }
        else if(s[n-1-i]!='0')cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}