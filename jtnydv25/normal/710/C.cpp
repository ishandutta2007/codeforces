#include <bits/stdc++.h>
using namespace std;
int arr[50][50];
#define F first
#define S second
pair<int,int> nextpos(int i, int j, int n)
{
    int tmpi = i,tmpj = j;
    i = (i-1)%n;
    if(i<0)
        i+=n;
    j = (j+1)%n;
    if(!arr[i][j])
    {
        return make_pair(i,j);
    }
    return make_pair((i+2)%n,tmpj);
}
int main()
{
    int n;
    cin>>n;
    int i = 0,j = n/2;
    int k = 1;
    while(!arr[i][j])
    {
        arr[i][j] = k;
        pair<int,int> p = nextpos(i,j,n);
        i = p.F;
        j = p.S;
        k++;
    }
    for(int i = 0;i<n;i++){
        for(int  j = 0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}