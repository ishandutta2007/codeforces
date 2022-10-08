G = {}
G['h'] = input()
G['a'] = input()
n = int(input())

M = {}

for i in range(n):
  [t,zn,gra,kartka] = input().split(" ")
  t = int(t)
  gra = int(gra)
  if (zn,gra) not in M:
      M[(zn,gra)] = 0
  if(M[(zn,gra)]>=2):
      continue
  if(kartka=="y"):
      M[(zn,gra)] += 1
  else:
      M[(zn,gra)] += 2
  if(M[(zn,gra)]>=2):
      print(G[zn],gra,t)