#include <bits/stdc++.h>
using namespace std;
int L=(1 << 17),R=(1 << 18),i,ans=0;
int main()
{
    int n,x;
    cin >> n >> x;
    if(n == 1){
        cout << "YES" << endl << x << endl;
    }
    else if(n==2 && x==0){
        cout << "NO";
        return 0;
    }
    else if(n==2){
        cout << "YES" << endl << "0 " << x;
    }
    else
    {
        cout << "YES" << endl;
        for(i=1;i<=n-3;i++){
        	ans^=i;
            cout << i << " ";}
        if(ans == x){
            cout << L+R << " " << L << " " << R;
        }
        else{
            cout << L << " " << ((L^x)^ans) << " 0";
        }
    }
}