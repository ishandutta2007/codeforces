#include<iostream>
using namespace std;
bool ap[1001];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        ap[x]=true;
    }
    for(int i=1;i<999;i++)
    {
        if(ap[i]&&ap[i+1]&&ap[i+2])
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}