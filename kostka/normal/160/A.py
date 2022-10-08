n = int(input())

wyn = 0

tab = input().split(" ")
for i in range(len(tab)):
  tab[i] = int(tab[i])
  wyn += tab[i]
  
tab.sort()

moje = 0

for i in range(len(tab)):
  wyn -= tab[n-i-1]
  moje += tab[n-i-1]
  if moje>wyn:
    print(i+1)
    break