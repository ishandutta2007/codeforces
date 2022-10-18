import re
print('NO'if re.search('[^aeiou%s]'*2%('n',''),input()+'x')else'YES')