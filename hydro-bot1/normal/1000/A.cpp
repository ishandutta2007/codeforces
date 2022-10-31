// Hydro submission #61289c17e8c33891cabef8fc@1630051351109
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string str;
    map<string,int> mp;
    for(int i=0;i<n;i++){
        cin>>str;
        mp[str]++;                  ///str0str
    }
    int m=0;
    for(int i=0;i<n;i++){
        cin>>str;
        if(mp[str]>=1){
           m++;
           mp[str]--;
        }
    }
    cout<<n-m<<endl;
    return 0;
}