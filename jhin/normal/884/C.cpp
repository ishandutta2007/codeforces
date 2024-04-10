#include <bits/stdc++.h>

using namespace std;
long long n,c,ans,a[100004];bool used[100004];
int main()
{
    cin>>n;
    vector <long long>s;// the number of stations for each loop of connected subways
    for(int i=0;i<n;i++)cin>>a[i]; //array of the stations
    for(int i=0;i<n;i++) // this for loop is to see how many stations connected to each other
    {
        int j=a[i]-1;c=0;
        if(used[j])continue; //if the station is used no need to do anything

        while(!used[j]) //counting how many stations in this part
        {
            used[j]=true;
            c++;j=a[j]-1;
        }
        s.push_back(c);// the number of stations connected (the more you know.. lol)
    }
    sort(s.begin(),s.end());// i want to connect the largest 2 loops of stations
    int j=s.size()-1;
   if(j>0){ s[j-1]+=s[j];s.erase(s.begin()+j);} // added the largest loop to the second largest loop then i delete the largest one
    for(int i=0;i<s.size();i++)ans+=s[i]*s[i]; // and finally each number of stations connected adds s[i]*s[i] to the ans
    cout<<ans;

    return 0;
}