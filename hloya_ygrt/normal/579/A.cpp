#include <iostream>

using namespace std;

int main()
{
    long long step[1000];
    int x;
    cin>>x;
    long long i=1;
    int j=0;
    while (i<=x){
        step[j]=i;
        i*=2;
        j++;
    }
    j--;
    int s=0;
    while (x!=0){
        for (i=j;i>=0;i--)
            if (step[i]<=x) { x-=step[i];s++;}

    }
    cout<<s;
    return 0;
}