def main():
    s = input()
    
    liters = [0 for i in range(26)]
    for i in s:
        liters[ord(i) - ord('a')] ^= 1
    
    c = liters.count(1)
    
    if c == 0 or c % 2 == 1:        #c % 2 or n % 2
        print("First")
    else:
        print("Second")

main()