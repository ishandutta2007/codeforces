def li():
  return list(map(int, input().split(" ")))
a = input()
if(a == "0"):
  print(15)
else:
  a = bin(int(a))[2:]
  a = "0"*(4-len(a)) + a
  a = a[::-1]
  a = int(a, 2)-1
  a =bin(a)[2:]
  a = "0"*(4-len(a)) + a
  a = a[::-1]
  print(int(a, 2))