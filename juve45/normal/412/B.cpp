#include <iostream>
#include <queue>
using namespace std;
priority_queue <int> q;
int n,k,ka;
int main()
{

    cin>>n>>k;

    for(int i=1;i<=n;i++)
        cin>>ka, q.push(ka);

        while(k!=1)
        {
            q.pop();
            k--;
        }
        cout<<q.top();
    return 0;
}