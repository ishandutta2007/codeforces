#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 4000+7;
int A[N];
vector<int> ans;
void flip(int l,int r){
    reverse(A+l,A+r+1);
    ans.push_back(r);
}
void solve(){
    int n;
    cin>>n;
    int flag = 0;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        if (A[i]%2!=i%2){
            flag = 1;
        }
    }
    if (flag){
        cout<<"-1\n";
        return;
    }
    int ptr = n;
    while(ptr>3){
        int pos1 = 0,pos2 = 0;
        for(int i = 1;i<=ptr;++i){
            if (A[i]==ptr)
                pos1 = i;
            if (A[i]==ptr-1)
                pos2 = i;
        }
        flip(1,pos1);
        if (pos2<pos1)
            pos2 = pos1+1-pos2;
        pos1 = 1;
        if (pos1+1!=pos2){
            flip(1,pos2-1);
            pos1 = pos2-1;
            flip(1,pos2+1);
            pos1 = 3;
            pos2 = 2;
            flip(1,3);
            pos1 = 1;
            pos2 = 2;
            flip(1,ptr);
            pos1 = ptr;
            pos2 = ptr-1;
        }
        else{
            flip(1,ptr);
            pos1 = ptr,pos2 = ptr-1;
        }
        ptr-=2;
    }
    if (ptr==3 && A[1]!=1)
        ans.push_back(3);
    cout<<ans.size()<<endl;
    for(auto to:ans)
        cout<<to<<' ';
    cout<<endl;
    ans.clear();
}
int main() {
    int t;
    t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}