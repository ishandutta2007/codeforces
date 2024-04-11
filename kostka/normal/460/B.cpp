//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

long long powe(long long a, long long b)
{
    long long res = 1LL;
    for(int i=0; i<b; i++)
    {
        res *= a;
        //cout << res << "\n";
    }
    return res;
}

int sum(long long a)
{
    int res = 0;
    while(a)
    {
        res += a%10;
        a /= 10;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    vector <long long> A;
    long long a, b, c;
    cin >> a >> b >> c;
    for(int i=0; i<=81; i++)
    {
        long long ttt = b*powe(i,a)+c;
        if(0 < ttt && ttt < 1000*1000*1000 && sum(ttt)==i)
            A.push_back(ttt); 
    }
    sort(A.begin(), A.end());
    cout << (int)A.size() << "\n";
    for(auto ele : A)
        cout << ele << " ";
    return 0;
}