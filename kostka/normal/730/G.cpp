//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 207;
int s[MAXN], d[MAXN];

//         odkad      dlugosc
set <pair <long long, long long> > Q, RQ;


int main()
{
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> s[i] >> d[i];
  Q.insert(make_pair(1, 1e18));
  //RQ.insert(make_pair(1e18, 1));
  for(int i=0; i<n; i++)
  {
    auto it = Q.upper_bound(make_pair(s[i], 1e18));
    if(it != Q.begin())
      it--;
    long long lewod, lewdl;
    tie(lewod, lewdl) = (*it);
    if(lewod <= s[i] and lewod + lewdl >= s[i]+d[i])
    {
      long long pozdl = s[i] - lewod;
      if(pozdl != 0)
      {
        Q.insert(make_pair(lewod, pozdl));
        //RQ.insert(make_pair(pozdl, lewod));
      }
      long long rozdl = (lewod + lewdl) - (s[i] + d[i]);
      if(rozdl != 0)
      {
        Q.insert(make_pair(s[i]+d[i], rozdl));
        //RQ.insert(make_pair(rozdl, s[i]+d[i]));
      }
      Q.erase(make_pair(lewod, lewdl));
      //RQ.erase(make_pair(lewdl, lewod));
      //cerr << "A ";
      cout << s[i] << " " << s[i]+d[i]-1 << "\n";
    }
    else
    {
      long long lewod, lewdl;
      for(auto it : Q)
      {
        tie(lewod, lewdl) = (it);
        if(lewdl >= d[i])
          break;
      }

      long long zos = lewdl - d[i];
      if(zos != 0)
      {
        //RQ.insert(make_pair(zos, lewod + d[i]));
        Q.insert(make_pair(lewod + d[i], zos));
      }
      Q.erase(make_pair(lewod, lewdl));
      //RQ.erase(make_pair(lewdl, lewod));
      //cerr << "B ";
      cout << lewod << " " << lewod + d[i]-1 << "\n";
    }
    /*/
    cerr << "---\n";

    for(auto ele : Q)
      cerr << ele.first << " " << ele.second << "\n";
    cerr << "---\n";
    //for(auto ele : RQ)
    //  cerr << ele.first << " " << ele.second << "\n";
    //  cerr << "---\n";
    /*/

  }
  return 0;
}