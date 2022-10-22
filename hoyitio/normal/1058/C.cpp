#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum = 0;
    for(int i = 0 ; i < n ; i++)
    {
        sum += (s[i]-'0');
    }
    if(sum==0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    int T = sum;
    bool ans = true;
    int cnt = 2;
    do{
        while(T%cnt != 0)
        {
            if(T/cnt==0)
            {
                break;
            }
            cnt++;
        }
        sum = T/cnt;
        cnt++;
       //cout<<"sum = "<<sum<<endl;
        int temp = 0;
        ans = true;
        for(int i = 0 ; i < n ; i++)
        {
            if(temp == sum&&s[i]!='0')
            {
                temp = 0;
            }
            temp += (s[i]-'0');
            if(temp > sum)
            {
                ans = false;
                break;
            }
        }
        if(ans&&temp == sum)
        {
            break;
        }
        else {
            ans = false;
        }
    }while(sum);
    ans?cout<<"YES"<<endl:cout<<"NO"<<endl;
    return 0;
}