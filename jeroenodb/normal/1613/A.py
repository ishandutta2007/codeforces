for _ in range(int(input())):
    x1,x2 = input().split(" ")
    y1,y2 = input().split(" ")

    l1 = len(x1) + int(x2)
    l2 = len(y1) + int(y2)

    if (l1 > l2):
        print(">")
        continue
    elif (l1 < l2):
        print("<")
        continue
        
    
    n1 = x1 + "0"*(int(x2) - min(int(x2),int(y2)))
    n2 = y1 + "0"*(int(y2) - min(int(x2),int(y2)))
    n1 = "0"*(max(0,len(n2)-len(n1))) + n1
    n2 = "0"*(max(0,len(n1)-len(n2))) + n2
    if (n1 == n2):
        print("=")
    elif (n1 < n2):
        print("<")
    else:
        print(">")