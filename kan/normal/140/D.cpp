#include <iostream>
#include <algorithm>

using namespace std;

const int maxn=105;

int a[maxn];

int main()
{
    int curtime,ans,answer;
    int n;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    curtime=10;
    ans=0;
    answer=0;
    for (int i=0;i<n;i++)
    {
        if (curtime+a[i]<=60*12)
        {
            ans++;
            curtime+=a[i];
            answer+=max(curtime-6*60,0);
        }
//        cerr << curtime << endl;
    }
    cout << ans << ' ' << answer << endl;
    return 0;
}