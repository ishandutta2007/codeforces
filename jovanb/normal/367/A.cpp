#include <bits/stdc++.h>
using namespace std;

char ch[100005];
long brx[100005],bry[100005],brz[100005];
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long m,i,l,r,x;
    cin>>ch;
    long n=strlen(ch);
    for(i=0;i<n;i++){
        brx[i+1]+=brx[i];
        bry[i+1]+=bry[i];
        brz[i+1]+=brz[i];
        if(ch[i]=='x')brx[i+1]++;
        else if(ch[i]=='y')bry[i+1]++;
        else brz[i+1]++;
    }
    cin>>m;
    for(i=0;i<m;i++){
        cin>>l>>r;
        x=min(brx[r]-brx[l-1],min(bry[r]-bry[l-1],brz[r]-brz[l-1]));
        if(brx[r]-brx[l-1]<=x+1 && bry[r]-bry[l-1]<=x+1 && brz[r]-brz[l-1]<=x+1)cout<<"YES\n";
        else if(r-l<2)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}