#include <bits/stdc++.h>
using namespace std;
int t,n,a,b,ub,lb,res,curr, c;
long long kk;
long long s;
vector <int> mm;
vector <pair<int,int>> V;
int main(){
    scanf("%d",&t);
    while(t--){

        mm.clear();
        V.clear();
        scanf("%d%lld", &n,&s);
        for(int i = 0; i < n ; i++){
            scanf("%d %d", &a, &b);
            V.push_back({a,b});
            mm.push_back(b);
            s-=a;
        }
        sort(V.begin(), V.end());
        nth_element(mm.begin(), mm.begin()+n/2, mm.end());
        res = mm[n/2];
        lb = 0, ub = res;
        while(lb <= ub){
            curr = (ub+lb)/2;
            c = 0, kk = 0;
            for(int i = n-1; i >=0 && c < (n+1)/2; i--){
                if(V[i].second>=curr){
                    kk += max(0,curr-V[i].first);
                    c++;
                }

            }
            if(s>=kk && c == (n+1)/2)lb = curr + 1;
            else ub = curr - 1;
        }
        cout << ub << "\n";
    }
    return 0;
}