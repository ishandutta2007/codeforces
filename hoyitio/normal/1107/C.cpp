#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const long long MAXN =  2e5+10;
long long a[MAXN];
bool cmp(long long a,long long b)
{
    return a > b;
}
int main()
{
    long long n,k;
    cin >> n >> k;
    for(long long i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    long long ans = 0;
    for(long long i = 0 ; i < s.length(); i++)
    {
        vector<long long> temp;
        temp.push_back(a[i]);
        while(i!=s.length()-1&&s[i+1]==s[i])
        {
            i++;
            temp.push_back(a[i]);
        }
        sort(temp.begin(),temp.end(),cmp);
        for(long long i = 0 ; i< temp.size() && i < k; i++)
        {
            //cout<<"temp[i] = "<<temp[i]<<endl;
            ans+=temp[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}