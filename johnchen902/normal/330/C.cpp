#include <iostream>

using namespace std;
char data[100][101];
int row[100], col[101];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> data[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(data[i][j] == '.'){
				row[i] = j + 1;
				col[j] = i + 1;
			}
		
	int i;		
	for(i = 0; i < n; i++)
		if(!row[i])
			break;
	if(i == n){ // good
		for(i = 0; i < n; i++)
			cout << i + 1 << " " << row[i] << endl;
		return 0;
	}
	for(i = 0; i < n; i++)
		if(!col[i])
			break;
	if(i == n){ // good
		for(i = 0; i < n; i++)
			cout << col[i] << " " << i + 1 << endl;	
		return 0;
	}
	// bad
	cout << -1 << endl;
	return 0;
}