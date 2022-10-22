#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n,m,k;
    cin >> n;
    string s;
    cin >> s;
    int a[3][3]={0};
    for(int i=0;i<n;i++){
        if (s[i]=='R'){
            a[i%3][0]++;
        }
        if (s[i]=='G'){
            a[i%3][1]++;
        }
        if (s[i]=='B'){
            a[i%3][2]++;
        }
    }
    char si,d,f;
    int ans=1e9;
    int t=(n+2)/3,t1=(n+1)/3,t2=n/3;
    if (t+t1+t2-a[0][0]-a[1][1]-a[2][2]<ans){
        si='R';
        d='G';
        f='B';
        ans=t+t1+t2-a[0][0]-a[1][1]-a[2][2];
    }
    if (t+t1+t2-a[0][0]-a[2][1]-a[1][2]<ans){
        si='R';
        d='B';
        f='G';
        ans=t+t1+t2-a[0][0]-a[2][1]-a[1][2];
    }
    if (t+t1+t2-a[1][0]-a[0][1]-a[2][2]<ans){
        si='G';
        d='R';
        f='B';
        ans=t+t1+t2-a[1][0]-a[0][1]-a[2][2];
    }
    if (t+t1+t2-a[1][0]-a[2][1]-a[0][2]<ans){
        si='B';
        d='R';
        f='G';
        ans=t+t1+t2-a[1][0]-a[2][1]-a[0][2];
    }
    if (t+t1+t2-a[2][0]-a[0][1]-a[1][2]<ans){
        si='G';
        d='B';
        f='R';
        ans=t+t1+t2-a[2][0]-a[0][1]-a[1][2];
    }
    if (t+t1+t2-a[2][0]-a[1][1]-a[0][2]<ans){
        si='B';
        d='G';
        f='R';
        ans=t+t1+t2-a[2][0]-a[1][1]-a[0][2];
    }
    cout << ans << endl;
    for(int i=0;i<n;i++){
        if (i%3==0){
            cout << si;
        }
        else if(i%3==1){
            cout << d;
        }
        else{
            cout << f;
        }
    }

}