#Codeforces - Soldier and Bananas

k, n, w = map(int, input().split())
tot = (int)((w*(w+1))/2)*k
tot -= n

if(tot<0): tot=0
print(tot)