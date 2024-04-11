i =input()
a =int("0b" + i.replace('7', '1').replace('4','0'), 2);
print(a+(2**(len(i)))-1)