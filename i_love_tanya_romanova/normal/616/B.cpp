/*
You opened my heart when you opened your eyes
And I beheld the dawn of the hidden sky
I felt a breeze, so gentle and mild
And when I glanced the sunrise, then I knew I could fly

Oh, I see the sky, in your eyes

Please grab my hand and take me away
Take me into your eyes to meet a beautiful day
Take me into the sky, where the birds always sing
And put me on a cloud, where dreams begin

Oh, I see the sky, in your eyes

And when sunset comes let me watch the stars
Don't close your eyes cause it would break my heart
Oh, please my love, please let me see
Don't close your eyes, cause you know it would kill me

Oh, I see the sky, in your eyes
Oh, a beautiful sky, down deep in your eyes
*/

//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-8
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

const int N = 2150;

using namespace std;

int n, m, bst[10000], ar[500][500];
int ans;

int main(){
	//freopen("route.in","r",stdin);
	//freopen("route.out","w",stdout);
	//	freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		bst[i] = 1e9;

		for (int j = 1; j <= m; j++)
		{
			cin >> ar[i][j];
			bst[i] = min(bst[i], ar[i][j]);
		}
		ans = max(ans, bst[i]);
	}

	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}