// Hydro submission #63454f6c55979fe86040ebd1@1665486701356
#include <iostream>
#include <map>
#include <string>

using namespace std;
map <string,bool> ds;
int n;
string s;
int main(){
    ds["ABSINTH"]=1;
    ds["BEER"]=1;
    ds["BRANDY"]=1;
    ds["CHAMPAGNE"]=1;
    ds["GIN"]=1;
    ds["RUM"]=1;
    ds["SAKE"]=1;
    ds["TEQUILA"]=1;
    ds["VODKA"]=1;
    ds["WHISKEY"]=1;
    ds["WINE"]=1;
    ds["0"]=1;
    ds["1"]=1;
    ds["2"]=1;
    ds["3"]=1;
    ds["4"]=1;
    ds["5"]=1;
    ds["6"]=1;
    ds["7"]=1;
    ds["8"]=1;
    ds["9"]=1;
    ds["10"]=1;
    ds["11"]=1;
    ds["12"]=1;
    ds["13"]=1;
    ds["14"]=1;
    ds["15"]=1;
    ds["16"]=1;
    ds["17"]=1;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>s;
        if(ds[s]) sum++;
    }
    cout<<sum;
    return 0;
}