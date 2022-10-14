    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<string>
    #include<cmath>
    #include<queue>
    #include<unordered_map>
    using namespace std; 
     
    int main(){
        int n,k; 
        cin >> n >> k; 
        int count = 0; 
        int storage[11]; 
        for(int m = 0; m < 11; m++){
            storage[m] = 0;
        }
        for(int i = 0; i < n; i++){
            string current; 
            cin >> current; 
            for(int j = 0; j < current.size(); j++){
                storage[current[j]-48] = 1;
            }
            bool flag = true; 
            for(int m = 0; m < k+1; m++){
                if(storage[m] == 0){
                    flag = false; 
                    break;
                }
            }
            if(flag){
                count++; 
            }
            for(int m = 0; m < k+1; m++){
                storage[m] = 0;
            }
        }
        cout << count << endl; 
        //resub
    }