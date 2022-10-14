def li():
  return list(map(int, input().split(" ")))
a = input()
# ban = [1, 7, 9, 10, 11, 13, 14, 15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,31,37,39,41,47,49,51,57,59,61,67,69,71,72,73,74,75,76,77,78,79,81,8]
if "9" in a:
  print("No")
elif "7" in a:
  print("No")
elif "1" in a and a != "12":
  print("No")
elif len(a)>1 and a[0] == "2":
  print("No")
else:
  print("Yes")