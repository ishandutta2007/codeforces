#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

main()
{int jeden, dwa;
cin >>jeden >>dwa;
vector <int> pierwszy(jeden);
vector <int> drugi (dwa);

for (int i=0; i<jeden; i++)
 cin >>pierwszy[i];

for (int i=0; i<dwa; i++)
 cin >>drugi[i];

sort (pierwszy.begin(), pierwszy.end());


for (int j=0; j<dwa; j++)
{cout << lower_bound(pierwszy.begin(), pierwszy.end(),drugi[j]+1)-pierwszy.begin()<<endl;


}

}