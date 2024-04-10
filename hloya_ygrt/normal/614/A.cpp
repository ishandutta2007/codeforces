#include <bits\stdc++.h>

using namespace std;
#define ull unsigned long long
int main()
{
    vector<ull> x;
    ull l,r,k,ans =1;
    bool f =0;
    cin >> l >> r >> k;
    ans = 1;

    while(ans < l){
        ans *= k;
    }


    while(ans <= r){
//if (f)
 //       cout<<' ';
    x. push_back(ans);
    f = 1;
    ans *= k;
}

    if(!f){
        cout << -1;
        exit(0);
    } else
    {
        f=0;
        sort(x.begin(),x.end());
        for (int i=0;i<x.size();i++){
            if (i==0){
    if (x[i]>=l&&x[i]<=r){
                if (x[i] == 1|| x[i] % k ==0)
                //if (x[i-1]!=x[i])
                    {cout<<x[i]<<' ';f=1;};
            }
            }else
            if (x[i]>=l&&x[i]<=r){
                if (x[i] == 1|| x[i] % k ==0)
                if (x[i-1]!=x[i])
                    {cout<<x[i]<<' ';f=1;};
            }

        }
    }
    if (!f){cout<<-1;}
return 0;
}