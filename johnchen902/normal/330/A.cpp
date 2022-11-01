#include <iostream>

using namespace std;

char data[10][11];
bool row[10], col[10];

int main(){
	int h, w;
	cin >> h >> w;
	for(int i = 0; i < h; i++)
		cin >> data[i];
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
			if(data[i][j] == 'S')
				row[i] = col[j] = true;
	int rows = 0;
	for(int i = 0; i < h; i++)
		if(row[i])
			rows++;
	int cols = 0;
	for(int i = 0; i < w; i++)
		if(col[i])
			cols++;
	cout << h * w - rows * cols << endl;
	return 0;
}