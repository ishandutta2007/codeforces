#include <bits/stdc++.h>
using namespace std;

string s, a, b;
void answer(int*m, int k) {
  int done[26] = {};
  for (int i = 0; i < k; i++)
    done[m[i]]++;
  int j = 0;
  for (int i = 0; i < k; i++)
    if (m[i] == -1) {
      while (done[j]) j++;
      m[i] = j;
      done[j] = 1;
    }
  static char key[100] = {};
  for (int i = 0; i < k; i++)
    key[i] = char(m[i]+'a');
  key[k] = 0;
  cout << "YES\n";// << endl;
  //printf("YES\n%s\n", key);
  cout << key << '\n';//endl;
  /*{
    string s_;
    for (char c : s) {
      s_ += key[c-'a'];
    }
    if (s_ < a || s_ > b) {
      cout << "ERROR!" << endl;
      cout << s << ' ' << a << ' ' << b << ' ' << key << endl;
    }
    }*/
}

int m[26], mi[26];
inline int put(char a, char b) {
  int&t = m[a], &ti = mi[b];
  if (t != -1 && t != b || ti != -1 && ti != a) return 1;
  t = b;
  ti = a;
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) m[i] = -1, mi[i] = -1;
    cin >> s >> a >> b;
    int n = s.size();
    for (int i = 0; i < n; i++)
      s[i] -= 'a', a[i] -= 'a', b[i] -= 'a';

    int i = 0;
    int ok = 1;
    for (; i < n; i++) {
      if (a[i] != b[i]) break;
      if (put(s[i], b[i])) {
	ok = 0;
	break;
      }
    }
    if (!ok) goto fail;
    if (i == n) {
      answer(m, k);
      continue;
    }
    for (int j = a[i]+1; j < b[i]; j++) {
      if (put(s[i], j)) continue;
      answer(m, k);
      goto next;
    }

    {
      int m2[26], mi2[26];
      copy_n(m, 26, m2);
      copy_n(mi, 26, mi2);
      int i_cp = i;

      if (!put(s[i], a[i])) {
	int ok = 1;
	i++;
	for (; i < n; i++) {
	  for (int j = a[i]+1; j < k; j++) {
	    if (put(s[i], j)) continue;
	    //cout << s << ' ' << i << ' ' << char(j) << endl;
	    answer(m, k);
	    goto next;
	  }
	  if (put(s[i], a[i])) {
	    ok = 0;
	    break;
	  }
	}
	if (i == n && ok) {
	  answer(m, k);
	  goto next;
	}
      }

      copy_n(m2, 26, m);
      copy_n(mi2, 26, mi);
      i = i_cp;
    }

    {
      if (!put(s[i], b[i])) {
	int ok = 1;
	i++;
	for (; i < n; i++) {
	  for (int j = 0; j < b[i]; j++) {
	    if (put(s[i], j)) continue;
	    answer(m, k);
	    goto next;
	  }
	  if (put(s[i], b[i])) {
	    ok = 0;
	    break;
	  }
	}
	if (i == n && ok) {
	  answer(m, k);
	  goto next;
	}
      }
    }

  fail:
    cout << "NO\n";
    //printf("NO\n");
    continue;
  next:
    ;
  }
}