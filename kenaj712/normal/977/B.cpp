#include<bits/stdc++.h>
using namespace std;
int tab[26][26];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int a;
    string b;
    cin>>a>>b;
    for(int x=0;x<b.size()-1;x++)
        tab[int(b[x])-65][int(b[x+1])-65]++;
    int maks=0;
    for(int x=0;x<26;x++)
        for(int y=0;y<26;y++)
            maks=max(maks,tab[x][y]);
    for(int x=0;x<26;x++)
        for(int y=0;y<26;y++)
            if(tab[x][y]==maks)
            {
                cout<<char(x+65)<<char(y+65);
                return 0;
            }

	return 0;
}