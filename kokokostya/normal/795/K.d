module main;

import std.c.stdio;

int main(string[] argv)
{
	int n;
	scanf("%d ", &n);
	char [] arr = new char[n];
	for(int i = 0; i < n; i++)
		scanf("%c", &arr[i]);
	for(int i = 0; i < n; i++){
	if(arr[i] == 'a' || arr[i] == 'i' || arr[i] == 'u' || arr[i] == 'y' || arr[i] == 'o' || arr[i] == 'e'){
    	if(i != n - 1 && arr[i] == arr[i + 1])
	        continue;
	   if(arr[i] == 'o' || arr[i] == 'e'){
	    if(i > 1 && arr[i - 2] == arr[i] && arr[i - 1] == arr[i]){
	    printf("%c", arr[i]);
	     continue;
	     }
	     if(i > 0 && arr[i - 1] == arr[i]){
	        printf("%c", arr[i]);
	     }
	   }
	   else
	   {
	    if(i && arr[i] == arr[i - 1]){
	    printf("%c", arr[i]);
	    continue;
	    }
	   }
    }
	    printf("%c", arr[i]);
	}
	return 0;
}