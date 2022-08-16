#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    int n;
    scanf("%d", &n);
    int sm = 0;
    for(int i = 1;i<=n;i++){
        scanf("%d", &a[i]);
        if(a[i] == 0){
            if(sm)
            {
                cout<<"NO";
                return 0;
            }
            sm = 0;
        }
        sm = (sm+a[i])%2;
    }
    cout<< ((sm==0)?"YES":"NO");
}