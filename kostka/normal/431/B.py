from itertools import permutations

tab = []

for i in range(5):
  buf = input().split(" ")
  X = []
  for j in range(5):
    X.append(int(buf[j]))
  tab.append(X)

res = 0

for perm in permutations([0,1,2,3,4], 5):
  wyn = 0
  wyn += tab[perm[0]][perm[1]]
  wyn += tab[perm[1]][perm[0]]
  wyn += tab[perm[2]][perm[3]]
  wyn += tab[perm[3]][perm[2]]
  
  wyn += tab[perm[1]][perm[2]]
  wyn += tab[perm[3]][perm[4]]
  wyn += tab[perm[2]][perm[1]]
  wyn += tab[perm[4]][perm[3]]
  
  wyn += tab[perm[2]][perm[3]]
  wyn += tab[perm[3]][perm[2]]
  
  wyn += tab[perm[3]][perm[4]]
  wyn += tab[perm[4]][perm[3]]
  
  res = max(wyn, res)
  
print(res)