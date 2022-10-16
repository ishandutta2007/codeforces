#include <iostream>

using namespace std;

long long N;

long long solve(long long k)
{
    if(k%3==0)
        return solve(k/3);
    else
        return k/3LL+1LL;
}

int main()
{

    cin>>N;
    cout<<solve(N);

    return 0;
}