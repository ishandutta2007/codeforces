a = input()

def check():
  if "H" in a:
    return True
  if "Q" in a:
    return True
  if "9" in a:
    return True
  return False

if check():
  print("YES")
else:
  print("NO")