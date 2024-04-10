// Hydro submission #61ab16e2ef9a89de1e760ffa@1638602466505
#include<bits/stdc++.h>
using namespace std;
struct st_n{
    string s;
    int num;
};
bool big(st_n a,st_n b){
    return a.s<b.s;
}
int main(){
    int m,n;
    vector<st_n> sr;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        st_n a;
        cin>>a.s;
        a.num=i;
        for(int i=1;i<m;i+=2) a.s[i]='Z'+'A'-a.s[i];
        sr.push_back(a);
    }
    sort(sr.begin(),sr.end(),big);
    cout<<sr[0].num;
    for(int i=1;i<n;i++){
        cout<<" "<<sr[i].num;
    }
    return 0;
}