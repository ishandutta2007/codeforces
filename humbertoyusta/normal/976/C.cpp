#include<bits/stdc++.h>
using namespace std;

struct seg{int l,r,id;
bool operator < ( const seg & other ){
    if(l != other .l) return l > other .l;
        else if(r != other .r) return r < other .r;
return id < other .id;
}
};

int n;
seg a[300005];

int main(){

ios_base::sync_with_stdio(0);
cin.tie(0);

///freopen("a.in","r",stdin);

cin >> n;

for(int i=1; i<=n; i++){
    cin>>a[i].l>>a[i].r;
    if(a[i].l<a[i].r) swap(a[i].l,a[i].r);
    a[i].id=i;
}

sort(a+1,a+n+1);

for(int i=1; i<=n; i++){
    if( a[i].l<=a[i-1].l && a[i].r>=a[i-1].r ){
        cout<<a[i].id<<' '<<a[i-1].id<<'\n';
        return 0;
    }
}

cout<<"-1 -1\n";

return 0;
}