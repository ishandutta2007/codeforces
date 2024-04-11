#include<bits/stdc++.h>

using namespace std;

const int N = 2000+1;

int n;
int p[N];

void do1(){
    for(int i = 0; i < n; ++i)
        swap(p[i<<1], p[i<<1|1]);
}

void do2(){
    for(int i = 0; i < n; ++i)
        swap(p[i], p[i+n]);
}

int check1(){
    int ans = 2*n;
    for(int i = 0; i < 2*n; ++i){
        do1();
        if(is_sorted(p, p+2*n)) ans = min(ans, 2*i+1);
        do2();
        if(is_sorted(p, p+2*n)) ans = min(ans, 2*i+2);
    }
    return ans;
}
int check2(){
    int ans = 2*n;
    for(int i = 0; i < 2*n; ++i){
        do2();
        if(is_sorted(p, p+2*n)) ans = min(ans, 2*i+1);
        do1();
        if(is_sorted(p, p+2*n)) ans = min(ans, 2*i+2);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < 2*n; ++i)
        cin >> p[i];
    if(is_sorted(p, p+2*n)){
        cout << "0\n";
        return 0;
    }
    int ans = min(check1(), check2());
    cout << (ans == 2*n ? -1 : ans) << "\n";
}