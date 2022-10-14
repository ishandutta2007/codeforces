#include <bits/stdc++.h>
using namespace std;
int N,t,c;
vector <int> a, b;
int main(){
    cin >> t;
    while(t--){
        cin >> N;
        a.clear(); b.clear();
        for(int i = 0; i < N; i++){
            scanf("%d",&c);
            a.push_back(c);
        }
        for(int i = 0; i < N; i++){
            scanf("%d",&c);
            b.push_back(c);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i = 0; i < N; i++)printf("%d ", a[i]);
        printf("\n");
        for(int i = 0; i < N; i++)printf("%d ", b[i]);
        printf("\n");
    }
    return 0;
}