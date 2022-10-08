n = input()
if(n.upper() == n):
  print(n.lower())
elif (n[1:].upper() == n[1:]):
  x = n[0].upper()
  n = n[1:].lower()
  print(x+n)
else:
  print(n)