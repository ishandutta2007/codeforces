n = int(input())

i = 0
ii = 1
while i<n:
  i += 5*ii
  ii *= 2

ii //= 2
i -= 5*ii

if i+1*ii>=n:
  print("Sheldon")
elif i+2*ii>=n:
  print("Leonard")
elif i+3*ii>=n:
  print("Penny")
elif i+4*ii>=n:
  print("Rajesh")
else:
  print("Howard")