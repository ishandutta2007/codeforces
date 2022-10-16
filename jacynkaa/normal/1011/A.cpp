#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin>>n>>k;

    vector <int> tab (30);

    string c;
    cin>>c;

    for (int i=0; i<c.size(); i++)
    {
        tab[c[i]-'a'+1]=1;
    }

    int wynik=0;
    int waga=0;

    for (int i=0; i<30; i++)
    {
        if(tab[i]!=0)
        {
            wynik++;
            waga+=i;
            i++;
        }

        if(wynik==k)
        {
            cout<<waga<<endl;;
            return 0;
        }
    }
    cout <<-1<<endl;
}